<script lang="ts">
	export let active: boolean = true;
	export let value = "";
</script>

<div
	class="grid grid-cols-3 items-center gap-5 rounded-xl bg-slate-50 p-5 {active
		? ''
		: 'opacity-50'}"
	style="grid-template-columns : 1fr 1fr 1fr ;"
>
	<div class="flex h-full w-full items-center justify-center">
		<img class=" h-full w-auto " src="clock.svg" alt="clock" />
	</div>
	<div class="flex h-full w-full items-center justify-center">
		<p class="font-bold">at</p>
	</div>
	<input
		class="w-full rounded-xl bg-slate-500 p-2 text-xl font-bold text-white"
		type="time"
		bind:value
		disabled={!active}
	/>
</div>
