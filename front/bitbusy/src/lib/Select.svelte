<script lang="ts">
    import { select, toggle } from "../select";
    import { settime, time } from "../timer";
    import { busy } from "../busy";
    import { get } from "svelte/store";

    function IO(){
        select.set(0);
        time.set(-1);
        if(get(busy)){
            toggle();
        }
    }

    function Timer(){
        select.set(1);  
        time.set(get(settime));
        if(get(busy)){
            toggle();
        }
    }
</script>

<div class="flex flex-row justify-center bg-black rounded-2xl items-center gap-5 w-full p-5" style="image-rendering: pixelated;">
    <button on:click={IO} aria-label="IO">
        <img class="h-20" class:saturate-5={$select == 1} alt="IO" src="IO.png">
    </button>
    <button on:click={Timer} aria-label="Timer">
        <img class="h-20" class:saturate-5={$select == 0} alt="Timer" src="timer.png">
    </button>
</div>