<script lang="ts">
 
</script>

<input type="range" id="timer" min="1" step="1" max="60">

<style>
#timer {
  appearance: none; 
  width: 305px;
  height: 6px;
  background: #ff7c04;
  border-radius: 5px;
  outline: none;
  cursor: pointer;
}

#timer::-webkit-slider-thumb {
  appearance: none;
  height: 24px;
  width: 24px;
  background: black;
  border: 2px solid #ff7c04;
  border-radius: 50%;
  cursor: pointer; 
}

#timer::-moz-range-thumb {
  height: 16px;
  width: 16px;
  background: black;
  border: 2px solid #ff7c04;
  border-radius: 50%;
  cursor: pointer;
}

#timer::-moz-range-track {
  background: transparent;
}
</style>