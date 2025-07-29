<script lang="ts">
    import { color, text } from "../running";
</script>

<div class="flex rounded-2xl flex-col justify-center items-center w-80 pb-5 pt-2" style="background-color: {$color};">
    <input bind:value={$text} type="text" class="font-lcd text-white text-[80px] w-76 h-20 text-center">
</div>

