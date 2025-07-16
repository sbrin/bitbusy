import { writable, get } from "svelte/store";

let interval: ReturnType<typeof setInterval>;

export const settime = writable(1800);
export const time = writable(1800);

export function timeString(){
    const minutes = Math.floor(get(time) / 60).toString().padStart(2, "0");
    const seconds = (get(time) % 60).toString().padStart(2, "0");
    return `${minutes}:${seconds}`;
}

export function start(){
    interval = setInterval(() => {
      time.update((current) => {
        if (current <= 1) {
          clearInterval(interval);
          time.set(get(settime));
          return 0;
        }
        return current - 1;
      });
    }, 1000);
}

export function hold(){
    clearInterval(interval);
}

export function stop(){
    clearInterval(interval);
    time.set(get(settime));
}