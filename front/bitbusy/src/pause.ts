import { writable, get } from "svelte/store";
import { busy } from "./busy";
import { hold, start } from "./timer";

export const pause = writable(true);

export function toggle(){
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
}