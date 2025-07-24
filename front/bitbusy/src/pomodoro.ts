import { pause } from "./pause";
import { get } from "svelte/store";
import { start, stop } from "./timer";
import { busy } from "./busy";
import { updateDevice } from "./update";

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

    await updateDevice();
}