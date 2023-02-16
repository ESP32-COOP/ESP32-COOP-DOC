<script lang="ts">
    export let active:boolean = false;
    export let icon:string = "";
    export let hint:string = "hint";
</script>

<button class="grid h-full w-11 grid-cols-1 items-center rounded-lg  text-sm {active ? " text-white bg-slate-600 " : "bg-slate-300  text-black" }"
style="grid-template-rows : 3fr 2fr ;" on:click={()=>active = !active}>
	<img class="m-auto {active ? "invert": ""}" src="{icon}.svg" alt="{icon}" />
	<p class="t text-center text-xs">{hint}</p>
</button>