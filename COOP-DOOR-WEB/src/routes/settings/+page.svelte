<script lang="ts">
	import OptionBadge from '$lib/components/OptionBadge.svelte';
	import LightInput from '$lib/components/LightInput.svelte';
	import TimeInput from '$lib/components/TimeInput.svelte';
	import RadioButton from '$lib/components/RadioButton.svelte';
	let settings = {
		close: { light: { active: true, value: 200 }, clock: { active: false, value: '20:30' } },
		open: { light: { active: true, value: 200 }, clock: { active: false, value: '20:30' } },
		door: { nbTurn: 5 }
	};
	let page: string | null = 'close';
	page = sessionStorage.getItem('page');

	$: sessionStorage.setItem('page', page == null ? 'close' : page);

	$: console.log(settings);
</script>

<div class="grid h-screen grid-cols-1 p-2 " style="grid-template-rows : 1fr 1fr 11fr ;">
	<div class="flex h-full w-full flex-row items-center">
		<a class="" href="/device">
			<div class=" m-2 ml-8 h-fit rounded-full bg-slate-300 bg-opacity-80 p-2">
				<img class="h-6 w-6 rotate-180 p-1" src="arrow.svg" alt="gear" />
			</div>
		</a>
	</div>
	<h1 class="ml-8 text-3xl uppercase">coop <span class="font-bold">settings</span></h1>
	<div class="flex h-full w-full items-center justify-center">
		<div
			class="grid h-4/5 w-4/5 grid-cols-1 gap-5 rounded-2xl bg-slate-300 p-5 opacity-70"
			style="grid-template-rows : 1.5fr 15fr ;"
		>
			<!--15fr-->
			<!-- nav-->
			<div class="flex items-baseline  justify-start gap-2 border-b-2 border-slate-500 ">
				<button
					class="rounded-xl p-1 px-3 {page == 'close'
						? 'h-full rounded-b-none  bg-slate-500  text-white'
						: 'h-[80%] bg-slate-50'} "
					on:click={() => (page = 'close')}>close</button
				>
				<button
					class="rounded-xl p-1 px-3 {page == 'open'
						? 'h-full rounded-b-none  bg-slate-500  text-white'
						: 'h-[80%] bg-slate-50'} "
					on:click={() => (page = 'open')}>open</button
				>
				<button
					class="rounded-xl p-1 px-3 {page == 'door'
						? 'h-full rounded-b-none  bg-slate-500  text-white'
						: 'h-[80%] bg-slate-50'} "
					on:click={() => (page = 'door')}>door</button
				>
			</div>
			<!-- nav end-->

			<!-- main menu-->

			{#if page == 'close'}
				<div
					class="grid h-full w-full grid-cols-1 gap-5"
					style="grid-template-rows : 2.5fr 5fr .5fr 5fr 2fr ;"
				>
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

					<LightInput
						bind:active={settings.close.light.active}
						bind:value={settings.close.light.value}
						direction="lower"
					/>

					<div class=" flex items-center">
						<select class="ml-5 rounded-md bg-slate-500 px-2 uppercase text-white">
							<option>and</option>
							<option>or</option>
						</select>
					</div>
					<TimeInput
						bind:active={settings.close.clock.active}
						bind:value={settings.close.clock.value}
					/>

					<button class="rounded-xl bg-slate-50 text-2xl font-bold uppercase">apply</button>
				</div>
			{:else if page == 'open'}
				<div
					class="grid h-full w-full grid-cols-1 gap-5"
					style="grid-template-rows : 2.5fr 5fr .5fr 5fr 2fr ;"
				>
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

					<LightInput
						bind:active={settings.open.light.active}
						bind:value={settings.open.light.value}
						direction="upper"
					/>

					<div class=" flex items-center">
						<select class="ml-5 rounded-md bg-slate-500 px-2 uppercase text-white">
							<option>and</option>
							<option>or</option>
						</select>
					</div>
					<TimeInput
						bind:active={settings.open.clock.active}
						bind:value={settings.open.clock.value}
					/>

					<button class="rounded-xl bg-slate-50 text-2xl font-bold uppercase">apply</button>
				</div>
			{:else if page == 'door'}
				<div
					class="grid h-full w-full grid-cols-2 gap-5 "
					style="grid-template-columns : 1fr 1.5fr ;"
				>
					<div class="grid h-full w-full grid-cols-1 gap-5" style="grid-template-rows: 4fr 1fr">
						<div class="flex items-center  justify-center rounded-xl bg-slate-50 relative">
							<input
								bind:value={settings.door.nbTurn}
								min="1"
								max="10"
								step="0.2"
								type="range"
								class="h-full w-full   opacity-0 z-10 "
								style=" -webkit-appearance: slider-vertical;"
								orient="vertical" 
							/>
							<div class="absolute w-full h-full p-2 flex flex-col justify-end">
								<div class="rounded-xl w-full bg-slate-500" style="height: { settings.door.nbTurn*10}%;"></div>
							</div>
						</div>
						<div class="flex flex-col items-center justify-center rounded-xl bg-slate-50">
							<h3 class="text-3xl">{settings.door.nbTurn}</h3>
							<p>turns</p>
						</div>
					</div>
					<div class="grid h-full w-full grid-cols-1 gap-5" style="grid-template-rows: 4fr 1fr">
						<RadioButton />
						<div class="grid h-full w-full grid-cols-2 gap-5 ">
							<button class="rounded-xl bg-slate-50 font-bold uppercase">test</button>
							<button class="rounded-xl bg-slate-50 font-bold uppercase">apply</button>
						</div>
					</div>
				</div>
			{:else}
				<p>error</p>
			{/if}

			<!-- main end-->
		</div>
	</div>
</div>
