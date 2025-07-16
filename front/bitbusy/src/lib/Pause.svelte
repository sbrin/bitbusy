<script lang="ts">
    import { pause, toggle } from "../pause";
    
    $: img = $pause ? "pause.png" : "resume.png"

    function onClick(){
        toggle();
    }
</script>

<button on:click={onClick} aria-label="pause" class="cursor-pointer"><img class="w-xs" src={img} alt=pause></button>