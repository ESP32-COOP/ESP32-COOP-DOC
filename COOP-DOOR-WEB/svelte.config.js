import adapter from '@sveltejs/adapter-auto';
import vercel from '@sveltejs/adapter-vercel'
import { vitePreprocess } from '@sveltejs/kit/vite';

/** @type {import('@sveltejs/kit').Config} */
const config = {
	// Consult https://kit.svelte.dev/docs/integrations#preprocessors
	// for more information about preprocessors
	preprocess: vitePreprocess(),

	kit: {
		//adapter: adapter() default
		adapter: vercel(),
	
	}
};

export default config;
