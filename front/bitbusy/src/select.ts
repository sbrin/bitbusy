import { writable } from "svelte/store";
import { pause } from "./pause";
import { start, stop, time } from "./timer";
import { busy } from "./busy";
import { get } from "svelte/store";

export const select = writable(1);

export async function toggle(){
    if(get(pause)){
        busy.set(!get(busy));
        pause.set(true);
        if(get(busy)){
            start();
        }
        else{
            stop();
        }
    }
    else{
        stop();
        pause.set(!get(pause));
    }

    try{
        const response = await fetch('/api/busy', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({
                "busy": get(busy),
                "time": get(time)
            })
        });
        if (!response.ok) {
            throw new Error('Network response was not ok');
        }
    }
    catch (error){
        console.error('Error sending busy:', error);
    }
}
