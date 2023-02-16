<script lang="ts">
	import OptionBadge from '$lib/components/OptionBadge.svelte';
	import LightInput from '$lib/components/lightInput.svelte';
	import TimeInput from '$lib/components/timeInput.svelte';
	let settings = {'close':{'light':{'active':true,'value':200}, 'clock':{'active':false,'value':"20:30"}},
		'open':{'light':{'active':true,'value':200}, 'clock':{'active':false,'value':"20:30"}}}
	let page = "close"

	$: console.log(settings);
</script>

<div class="grid h-screen grid-cols-1 p-2 " style="grid-template-rows : 1fr 1fr 11fr ;">
	<div class="flex h-full w-full flex-row items-center">
		<a class="" href="/device">
			<div class=" m-2 h-fit rounded-full bg-slate-300 bg-opacity-80 p-2">
				<img class="h-6 w-6 rotate-180 p-1" src="arrow.svg" alt="gear" />
			</div>
		</a>
	</div>
	<h1 class="ml-8 text-3xl uppercase">coop <span class="font-bold">settings</span></h1>
	<div class="flex h-full w-full items-center justify-center">
		<div
			class="grid h-4/5 w-4/5 grid-cols-1 gap-5 rounded-2xl bg-slate-300 p-5 opacity-70"
			style="grid-template-rows : 1.5fr 2fr 5fr .5fr 5fr 2fr ;"
		>
			<!-- nav-->
			<div class="flex items-baseline  justify-start gap-2 border-b-2 border-slate-500 ">
				<button class="rounded-xl p-1 px-3 {page=="close" ? "rounded-b-none h-full  bg-slate-500  text-white": "h-[80%] bg-slate-50"} " on:click={()=>page="close"}>close</button>
				<button class="rounded-xl p-1 px-3 {page=="open" ? "rounded-b-none h-full  bg-slate-500  text-white": "h-[80%] bg-slate-50"} " on:click={()=>page="open"}>open</button>
				<button class="rounded-xl p-1 px-3 {page=="door" ? "rounded-b-none h-full  bg-slate-500  text-white": "h-[80%] bg-slate-50"} " on:click={()=>page="door"}>door</button>
			</div>
			<!-- nav end-->

			<!-- main menu-->

			{#if page=="close"}


			<div
				class="grid grid-cols-2 items-center gap-2 rounded-xl bg-slate-50 p-1"
				style="grid-template-columns : 4rem 1fr ;"
			>
				<h3 class="ml-2">option</h3>
				<div class="flex h-full w-full flex-row gap-2">

					<OptionBadge icon="light" hint="light" bind:active={settings.close.light.active} />
					<OptionBadge icon="clock" hint="time" bind:active={settings.close.clock.active} />

				</div>
			</div>
			

			<LightInput bind:active={settings.close.light.active} bind:value={settings.close.light.value} direction="lower"/>

			<div class=" flex items-center">
				<select class="ml-5 rounded-md bg-slate-500 px-2 uppercase text-white">
					<option>and</option>
					<option>or</option>
				</select>
			</div>
			<TimeInput bind:active={settings.close.clock.active} bind:value={settings.close.clock.value} />

			{:else if page=="open"}


			<div
				class="grid grid-cols-2 items-center gap-2 rounded-xl bg-slate-50 p-1"
				style="grid-template-columns : 4rem 1fr ;"
			>
				<h3 class="ml-2">option</h3>
				<div class="flex h-full w-full flex-row gap-2">

					<OptionBadge icon="light" hint="light" bind:active={settings.open.light.active} />
					<OptionBadge icon="clock" hint="time" bind:active={settings.open.clock.active} />

				</div>
			</div>
			

			<LightInput bind:active={settings.open.light.active} bind:value={settings.open.light.value} direction="upper"/>

			<div class=" flex items-center">
				<select class="ml-5 rounded-md bg-slate-500 px-2 uppercase text-white">
					<option>and</option>
					<option>or</option>
				</select>
			</div>
			<TimeInput bind:active={settings.open.clock.active} bind:value={settings.open.clock.value} />


			{:else if page=="door"}
				<p>to come</p>
			{:else}
				<p>error</p>
			{/if}

			<!-- main end-->

			<button class="rounded-xl bg-slate-50 text-2xl font-bold uppercase">apply</button>
		</div>
	</div>
</div>
