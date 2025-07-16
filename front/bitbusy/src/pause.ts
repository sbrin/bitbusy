import { writable, get } from "svelte/store";

export var pause = writable(false);

export function toggle(){
    pause.set(!get(pause));
}