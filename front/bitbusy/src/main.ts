import { mount } from 'svelte'
import { busy } from './busy'
import { start } from './timer'
import { time } from './timer'
import './app.css'
import App from './App.svelte'
import { get } from 'svelte/store'
import { select } from './select'

const app = mount(App, {
  target: document.getElementById('app')!,
})

export async function load(){
  try{
      const response = await fetch('/api/busy', {
          method: 'GET',
        });
        if (!response.ok) {
            throw new Error('Network response was not ok');
        }
      const data = await response.json();

      console.log(data);
      busy.set(data.busy);
      
      if(data.busy){
        time.set(data.time);
        if(get(time) == -1){
          select.set(0);
        }
        else{
          start();
        }
      }
  }
  catch (error){
    console.error('Error getting busy:', error);
  }
}

export default app
