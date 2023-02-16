<script lang="ts">
    export let active:boolean = true;
    export let direction:string = "lower";
    export let value =200;

</script>

<div
	class="grid grid-cols-3 items-center gap-5 rounded-xl bg-slate-50 p-5 {active ? "" : "opacity-50" }"
	style="grid-template-columns : 1fr 1fr 1fr ;"
>
	<div class="flex h-full w-full items-center justify-center">
		<img class="m-auto h-full w-full " src="light.svg" alt="light" />
	</div>
	<div class="flex h-full w-full items-center justify-center">
		<img class="m-auto w-7 {direction == "lower" ? "rotate-180" : ""} " src="arrow.svg" alt="arrow" />
	</div>
	<input
		class="w-full rounded-xl bg-slate-500 p-2 text-xl font-bold text-white"
		type="number"
		bind:value={value}
        disabled = {!active}
	/>
</div>
