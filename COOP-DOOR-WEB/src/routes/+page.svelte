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

<h1>Welcome to SvelteKit</h1>
<p>Visit <a href="https://kit.svelte.dev">kit.svelte.dev</a> to read the documentation</p>

<a href="settings"><BigTitle/></a>

<button on:click={() => {count++;}}>add 1</button>

<p> test count = {count}</p>


<SmallBadge { ...SmallBadgeData} value={count} />