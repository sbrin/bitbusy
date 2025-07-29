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

    function String(){
        select.set(3);
    }

    function Pomodoro(){
        select.set(2);
        if(get(busy)){
            toggle();
        }
        time.set(get(settime));
    }
</script>

<div class="flex flex-row justify-center items-center w-full gap-2" style="image-rendering: pixelated;">
    <button class="flex rounded-2xl bg-black p-2.5 justify-center items-center" on:click={IO} aria-label="IO">
        <img class="w-13.5" class:saturate-5={$select != 0} alt="IO" src="IO.png">
    </button>
    <button class="flex rounded-2xl bg-black p-2.5 justify-center items-center" on:click={Timer} aria-label="Timer">
        <img class="w-13.5" class:saturate-5={$select != 1} alt="Timer" src="timer.png">
    </button>
    <button class="flex rounded-2xl bg-black p-2.5 justify-center items-center" on:click={Pomodoro} aria-label="Pomodoro">
        <img class="w-13.5" class:saturate-5={$select != 2} alt="Pomodoro" src="tomato.png"> 
    </button>
    <button class="flex h-18.5 rounded-2xl bg-black p-2.5 justify-center items-center" on:click={String} aria-label="String">
        <img class="w-13.5" class:saturate-5={$select != 3} alt="String" src="string.png"> 
    </button>
</div>