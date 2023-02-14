<script lang="ts">
	import { goto } from "$app/navigation";



    function connect() {
        goto("device");
    }
    </script>

<div class="p-2 h-screen grid grid-cols-1 bg-opacity-20 bg-slate-600   " style="grid-template-rows : 1fr 1fr 8fr 3fr;">
    <div class="w-full h-full flex flex-row items-center ">
        
    </div>

    <h1 class=" uppercase text-3xl ml-8">connect <span class="font-bold">device</span></h1>
    <div class=" bg-[url('/connect.svg')] bg-no-repeat bg-center">

    </div>
    <div class="h-full w-full flex justify-center items-center">
        <button on:click={ connect} class="bg-gradient-to-r from-slate-700 to-slate-900 rounded-3xl w-72 flex justify-center items-center h-20 text-white text-5xl uppercase">
            connect
        </button>


    </div>


</div>

