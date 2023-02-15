<script lang="ts">
	import { onMount } from "svelte";

    let lightValue = 40;
    let minValue = 30;
    let maxValue = 60;



    function rand(){

        lightValue = Math.floor(Math.random() * (100 - 0 + 1) );

        setTimeout(rand,2000)
    }


onMount( async ()=>{
    rand();

})

</script>

<h1 class="uppercase text-3xl ml-8">light <span class="font-bold">sensor</span></h1>
<div class="w-full h-full flex items-center justify-center">
    <div class="rounded-2xl bg-gradient-to-r  from-blue-900 to-slate-900 opacity-70 w-4/5 h-[60%]">
        <div class="grid w-full h-full" style="grid-template-rows : 2fr 8fr 2fr ">
            <div class="w-full h-full flex items-center justify-center">
                <div class="rounded-2xl bg-slate-200/20  m-5 w-full h-auto flex items-center ">
                    <div style="width: {lightValue}%;" class=" rounded-xl m-2 bg-gradient-to-r from-red-400 to-yellow-200  h-20  transition-all">
                    </div>
                </div>
            </div>
            <div class="grid w-full h-full columns-1">
                <div class="w-full h-full flex items-center justify-center">
                    <div class="rounded-2xl bg-slate-200/20 m-5 w-full h-full grid grid-cols-2 items-center justify-center gap-3">
                        <p class="text-white/60 text-xl text-right">value : </p><h2 class="text-white text-5xl">{lightValue}</h2>
                    </div>
                </div>
                <div class="w-auto h-full columns-2 m-5 gap-5">
                    <div class="rounded-2xl bg-slate-200/20  w-full h-full flex flex-col justify-center items-center">
                        <h3 class="text-white text-4xl">{minValue}</h3>
                        <p class="text-white/60">min</p>
                        
                    </div>
                    <div class="rounded-2xl bg-slate-200/20  w-full h-full flex flex-col justify-center items-center">
                        <h3 class="text-white text-4xl">{maxValue}</h3>
                        <p class="text-white/60">max</p>
                    </div>

                </div>


            </div>
            <div class="flex items-center justify-center w-full h-full">
                <button class="uppercase bg-slate-500/50 rounded-xl m-5 w-full h-24 text-white text-2xl " >reset</button>
            </div>
        </div>

        

    </div>
</div>