<script lang="ts">
  import Busy from './lib/Busy.svelte'
  import Pause from './lib/Pause.svelte'
    import Timer from './lib/Timer.svelte';
</script>

<main class="bg-neutral-900">
  <div class="flex flex-col items-center justify-center h-screen gap-5">
    <Timer />
    <div class="flex flex-col items-center gap-2">
      <Busy />
      <Pause />
    </div>
  </div>
</main>
