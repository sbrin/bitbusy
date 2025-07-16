import { writable, get } from "svelte/store";

export var busy = writable(false);

export function toggle(){
    busy.set(!get(busy));
}