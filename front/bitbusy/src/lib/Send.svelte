<script lang="ts">
    import { updateDevice } from "../update";

    async function onClick(){
        await updateDevice();
    }

</script>

<button on:click={onClick} class="bg-black rounded-2xl px-7 py-7" aria-label="send" style="image-rendering: pixelated;">
    <img class="w-67" alt="send" src="send.png"/>
</button>   