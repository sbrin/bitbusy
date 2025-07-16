import { writable, get } from "svelte/store";
import { pause } from "./pause";
import { start, stop } from "./timer";

export const busy = writable(false);

export function toggle(){
    busy.set(!get(busy));
    pause.set(true);
    if(get(busy)){
        start();
    }
    else{
        stop();
    }
}