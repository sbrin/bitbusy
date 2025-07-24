import { writable, get } from "svelte/store";
import { pause } from "./pause";
import { start, stop } from "./timer";
import { updateDevice } from "./update";

export const busy = writable(false);

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

    await updateDevice();
}