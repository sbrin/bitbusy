import { writable, get } from "svelte/store";
import { busy } from "./busy";
import { tick } from "svelte";
import { derived } from "svelte/store";
import { select } from "./select";
import { pomobusy, toggle } from "./pomodoro";

export let interval: ReturnType<typeof setInterval>;

export const settime = writable(1800);
export const time = writable(1800);

export const timeString = derived(time, ($time) => {
  if($time > 0){
    const minutes = Math.floor($time / 60);
    const seconds = $time % 60;
    return `${minutes.toString().padStart(2, "0")}:${seconds.toString().padStart(2, "0")}`;
  }
    const minutes = Math.floor(get(settime) / 60);
    const seconds = get(settime) % 60;
    return `${minutes.toString().padStart(2, "0")}:${seconds.toString().padStart(2, "0")}`;
});

export async function start(){
  if(get(time) != -1){
    interval = setInterval(async () => {
      time.update((current) => {
        if (current <= 1) {
          stop();
          if(get(select) == 2){
            toggle();
            pomobusy.set(true);
            if(!get(busy)){
              time.set(get(settime) / 5);
            }
            else{ 
              time.set(get(settime));
            }
            return get(time);
          }
          else{
            busy.set(!get(busy));
          }
          return 0;
        }
        return current - 1;
      });
      await tick();
    }, 1000);
  }
}

export function hold(){
    clearInterval(interval);
}

export function stop(){
    clearInterval(interval);
    if(get(select) != 0){
      time.set(get(settime));
    }
}