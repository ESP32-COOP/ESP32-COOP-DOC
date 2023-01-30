<script lang=ts>
    export let badgeType: string = "ligh";
    export let title: string = "Title" ;
    export let subTitleType: string = "string";
    export let value: number = 0;
    export let subTitle: string = "Sub Title";

</script>

<div class="bg-gradient-to-r from-blue-900 to-slate-900 rounded-2xl p-2 grid grid-cols-1">
    

    <div class="flex  items-center">
        <h2 class="text-white text-2xl font-sans">{title}</h2>
    </div>

    <div class="flex  items-center">
        {#if (subTitleType == "string")}

        <p class="text-white  font-sans">{subTitle}</p>
            
        {:else if (subTitleType != "string")}
            
        <p class="text-white  font-sans">{value}</p>

        {/if}
    </div>

    <div class="flex justify-center items-center">
        <button class="bg-yellow-300 rounded-2xl align-middle max-w-min p-1 px-3 -px3">Détail</button>
    </div>
</div>