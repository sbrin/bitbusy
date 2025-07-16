<script lang="ts">
    import { busy, toggle } from "../busy";

    $: img = $busy ? "busy.png" : "free.png";

    function onClick(){
        toggle();
    }

</script>

<button on:click={onClick} class="cursor-pointer" aria-label="busy"><img class="w-xs" src={img} alt={$busy ? "busy" : "free"}></button>