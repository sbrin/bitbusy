import { writable } from "svelte/store";
import { pause } from "./pause";
import { start, stop, time } from "./timer";
import { busy } from "./busy";
import { get } from "svelte/store";

export const select = writable(1);
