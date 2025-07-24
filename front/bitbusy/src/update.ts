import { time } from "./timer";
import { busy } from "./busy";
import { get } from "svelte/store";

export async function updateDevice(){
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