<script lang="ts">
    import BigTitle from '$lib/components/BigTitle.svelte';
    import SmallBadge from '$lib/components/SmallBadge.svelte';

    let count = 1;

    const lightSmallBadgeData = {
        title: 'Light Sensor',
        subTitle: 'britness level',
        subTitleType: "value",
        value: count,
        badgeType: "dark"

    }

    const dateSmallBadgeData = {
        title: 'Date Time',
        subTitle: 'britness level',
        subTitleType: "value",
        icon: "clock",

    }
</script>

<div class="p-2 h-screen grid grid-cols-1 " style="grid-template-rows : 1fr 1fr 8fr 3fr;">
    <div class="w-full h-full flex flex-row items-center">
        <div class=" ml-auto bg-opacity-80 bg-slate-300 h-fit m-2 p-2 rounded-full">
            <img src="gear.svg" alt="gear">
        </div>
    </div>

    <h1 class="uppercase text-3xl ml-8">coop <span class="font-bold">door</span></h1>
    <div class="bg-[url('/coop.svg')] bg-no-repeat bg-center">

    </div>
    <div class="h-full mx-4    grid grid-cols-2 gap-4 w-auto">

        <SmallBadge { ...lightSmallBadgeData} value={count} />
        <SmallBadge { ...dateSmallBadgeData} value={count} />
        
    </div>

</div>

