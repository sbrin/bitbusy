import { writable, get } from "svelte/store";
import { pause } from "./pause";
import { start, stop, settime, time } from "./timer";

export const busy = writable(false);

export async function toggle(){
    if(get(pause)){
        time.set(get(settime));
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
                "time": get(settime)
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