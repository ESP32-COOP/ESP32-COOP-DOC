<script lang="ts">
    let value = 0;
    export function load() {
        return {
            number : value
        };
    }

    setTimeout(() => {
        value = value + 10;
    }, 2000);

    
</script>

<p> Wellcome to </p><h3>Settings</h3>

<p>Hello n {value}</p>

<a href="/">retour</a>