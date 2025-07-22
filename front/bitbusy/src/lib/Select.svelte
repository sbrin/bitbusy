<script lang="ts">
    import { select } from "../select";
</script>

<div class="flex flex-row justify-center bg-black rounded-2xl items-center gap-5 w-full p-5" style="image-rendering: pixelated;">
    <button aria-label="IO">
        <img class="h-20" class:saturate-5={$select == 0} alt="IO" src="IO.png">
    </button>
    <button aria-label="Timer">
        <img class="h-20" class:saturate-5={$select == 1} alt="Timer" src="timer.png">
    </button>
</div>