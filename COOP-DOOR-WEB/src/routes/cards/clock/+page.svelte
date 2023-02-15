<script lang="ts">


let datePhone = new Date();
let dateDevice = new Date(datePhone.getTime() + 2*60000);


</script>

<h1 class="uppercase text-3xl ml-8">date <span class="font-bold">time</span></h1>
<div class="w-full h-full flex items-center justify-center">
    <div class="rounded-2xl bg-slate-300 opacity-70 w-4/5 h-[60%] grid grid-cols-1 p-5 gap-5" style="grid-template-rows : 5fr 2fr 2fr ">
        <div class=" h-full w-full rounded-xl grid grid-cols-2 gap-5" >
            <div class="h-full w-full bg-slate-50 rounded-xl flex flex-col justify-around items-center">
                <h2 class="text-5xl">{dateDevice.getHours()}:{dateDevice.getMinutes()}</h2>
                <h3 class="text-3xl">{dateDevice.getDay()}/{dateDevice.getMonth()}/{dateDevice.getFullYear()}</h3>
                <p class="text-black/80">device</p>
            </div>

            <div class="h-full w-full bg-slate-50 rounded-xl flex flex-col justify-around items-center">
                <h2 class="text-5xl">{datePhone.getHours()}:{datePhone.getMinutes()}</h2>
                <h3 class="text-3xl">{datePhone.getDay()}/{datePhone.getMonth()}/{datePhone.getFullYear()}</h3>
                <p class="text-black/80">phone</p>
            </div>

        </div> 

        <div class="bg-slate-50 rounded-xl grid grid-cols-2 items-center justify-center gap-5">
            <p class=" text-right ">delta :</p>
            <h4 class="text-red-500 text-3xl">{(dateDevice - datePhone)/60000} min</h4>

        </div>

        <button class="bg-slate-50 rounded-xl uppercase text-xl font-semibold">
            sync device
        </button>


    </div>
</div>