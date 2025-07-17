import { writable, get } from "svelte/store";
import { busy } from "./busy";
import { hold, start } from "./timer";
import { time } from "./timer";

export const pause = writable(true);

export async function toggle(){
    if(get(busy) || !get(pause)){
        pause.set(!get(pause));
        busy.set(get(pause));
        
        if(get(pause)){
            start();
        }
        else{
            hold();
        }
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