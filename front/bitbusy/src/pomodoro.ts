import { pause } from "./pause";
import { get } from "svelte/store";
import { time, start, stop } from "./timer";
import { busy } from "./busy";

export async function toggle(){
    if(get(pause)){
        busy.set(!get(busy));
        pause.set(true);
        start();
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