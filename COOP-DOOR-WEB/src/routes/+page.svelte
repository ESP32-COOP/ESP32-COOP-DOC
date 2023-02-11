<script lang="ts">
    import BigTitle from '$lib/components/BigTitle.svelte';
    import SmallBadge from '$lib/components/SmallBadge.svelte';

    let count = 1;

    const SmallBadgeData = {
        title: 'Light Sensor',
        subTitle: 'britness level',
        subTitleType: "value",
        value: count,

    }
</script>

<div class="p-2 h-screen grid grid-cols-1 " style="grid-template-rows : 1fr 1fr 6fr 3fr;">
    <p>button</p>
    <h1 class="uppercase text-3xl ml-8">coop <span class="font-bold">door</span></h1>
    <div class="">

    </div>
    <div class="h-full mx-4    grid grid-cols-2 gap-4 w-auto h-40">

        <SmallBadge { ...SmallBadgeData} value={count} />
        <SmallBadge { ...SmallBadgeData} value={count} />
        
    </div>

</div>

