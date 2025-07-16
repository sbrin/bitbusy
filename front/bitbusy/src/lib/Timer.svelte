<script lang="ts">
  import { busy } from "../busy";
  $: cl = $busy ? "#e01b24" : "#33d17a";
</script>

<input disabled={$busy} style="--timer-color: {cl};" type="range" id="timer" min="1" step="1" max="60">

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