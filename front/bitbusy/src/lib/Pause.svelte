<script lang="ts">
    import { pause, toggle } from "../pause";
    import { select } from "../select";
    
    $: img = $pause ? "pause.png" : "resume.png"

    function onClick(){
        toggle();
    }
</script>

<button on:click={onClick} class:collapse={$select == 0} aria-label="pause" class="cursor-pointer"><img class="w-xs" src={img} alt=pause></button>