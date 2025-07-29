import { time } from "./timer";
import { busy } from "./busy";
import { get } from "svelte/store";
import { select } from "./select";
import { color, hexToRGB565, text } from "./running";

export async function updateDevice(){
    var req = {};
    if(get(select) == 3){
        req = { "running": true, "color": hexToRGB565(get(color)), "text": get(text)}
    }
    else{
        req = { "busy": get(busy), "time": get(time), "pomodoro": get(select) == 2 }
    }
    try{
        const response = await fetch('/api/busy', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify(req)
        });
        if (!response.ok) {
            throw new Error('Network response was not ok');
        }
    }
    catch (error){
        console.error('Error sending busy:', error);
    }
}