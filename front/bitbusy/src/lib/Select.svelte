<script lang="ts">
    import { select } from "../select";
    import { settime, time } from "../timer";
    import { busy, toggle } from "../busy";
    import { get } from "svelte/store";

    function IO(){
        select.set(0);
        if(get(busy)){
            toggle();
        }
        time.set(-1);
    }

    function Timer(){
        select.set(1);  
        if(get(busy)){
            toggle();
        }
        time.set(get(settime));
    }

    function Pomodoro(){
        select.set(2);
        if(get(busy)){
            toggle();
        }
        time.set(get(settime));
    }
</script>

<div class="flex flex-row justify-center bg-black rounded-2xl items-center gap-5 w-full p-5" style="image-rendering: pixelated;">
    <button on:click={IO} aria-label="IO">
        <img class="h-20" class:saturate-5={$select != 0} alt="IO" src="IO.png">
    </button>
    <button on:click={Timer} aria-label="Timer">
        <img class="h-20" class:saturate-5={$select != 1} alt="Timer" src="timer.png">
    </button>
    <button on:click={Pomodoro} aria-label="Pomodoro">
        <img class="h-20" class:saturate-5={$select != 2} alt="Pomodoro" src="tomato.png"> 
    </button>
</div>