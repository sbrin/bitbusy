<script>
    import Timer from "./Timer.svelte";
    import { timeString } from "../timer";
    import { busy } from "../busy";

    $: cl = $busy ? "font-lcd text-[#e01b24] text-[90px] -mt-5 ml-3" : "font-lcd text-[#33d17a] text-[90px] -mt-5 ml-3";
</script>

<div class="flex bg-black rounded-2xl p-2 flex-col items-center pb-4">
    <p class={cl}>{$timeString}</p>
    <Timer />
</div>