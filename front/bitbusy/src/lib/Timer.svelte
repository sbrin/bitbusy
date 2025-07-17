<script lang="ts">
  import { get } from "svelte/store";
  import { busy } from "../busy";
  import { settime, time } from "../timer";
  
  $: cl = $busy ? "#e01b24" : "#33d17a";

  function onInput(event: Event){
    const input = event.target as HTMLInputElement;
    settime.set(+input.value * 60);
    if(!$busy){
      time.set(get(settime));
    }
  }
</script>

<input oninput={onInput} disabled={$busy} style="--timer-color: {cl};" type="range" id="timer" min="0" step="1" value={settime} max="60">

<style>
#timer {
  appearance: none; 
  width: 280px;
  height: 6px;
  background: var(--timer-color);
  border-radius: 5px;
  outline: none;
  cursor: pointer;
}

#timer::-webkit-slider-thumb {
  appearance: none;
  height: 24px;
  width: 24px;
  background: black;
  border: 2px solid var(--timer-color);
  border-radius: 50%;
  cursor: pointer; 
}

#timer::-moz-range-thumb {
  height: 16px;
  width: 16px;
  background: black;
  border: 2px solid var(--timer-color);
  border-radius: 50%;
  cursor: pointer;
}

#timer::-moz-range-track {
  background: transparent;
}
</style>