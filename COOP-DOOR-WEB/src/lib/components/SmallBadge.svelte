<script lang=ts>
    export let badgeType: string = "ligh";
    export let title: string = "Title" ;
    export let subTitleType: string = "string";
    export let value: number = 0;
    export let subTitle: string = "Sub Title";

</script>



<h2>{title}</h2>

{#if (subTitleType == "string")}

<p>{subTitle}</p>
    
{:else if (subTitleType != "string")}
    
<p>{value}</p>

{/if}