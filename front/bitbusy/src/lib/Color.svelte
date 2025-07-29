<script lang="ts">
    import { color } from "../running";
</script>

<div class="flex flex-row text-white text-5xl font-sans font-bold bg-black p-2 rounded-2xl w-80 justify-center items-center gap-2">
    <p class="mb-0.5">Color:</p>
    <input class="rounded-2xl h-15.5 w-60" type="color" bind:value={$color} >
</div>

<style>
  input[type="color"] {
    border: none;
    outline: none;
    background: transparent;
    padding: 0;
    margin: 0;
  }

  input[type="color"]::-webkit-color-swatch-wrapper {
    padding: 0;
  }

  input[type="color"]::-webkit-color-swatch {
    border: none;
    border-radius: 8px;
  }

  input[type="color"]::-moz-color-swatch {
    border: none;
    border-radius: 8px;
  }
</style>

