import { Injectable } from '@angular/core';
import { getAuth,signInWithEmailAndPassword } from "firebase/auth";
import { initializeApp } from "firebase/app";
import { getDatabase, ref, set, onValue } from "firebase/database";
import {firebaseConfig, login} from "../environments/environment"
import { Subject } from 'rxjs';




let start: number = 0;
let previousTimeStamp: number = 0;
let timeout_threshold: any = 3000; //3 Seconds
let start_flag:boolean = false;
let done:boolean = false;
const hit_timeout$ = new Subject<any>();


function startCount(){
  start_flag = true;
}

/**
 * this is used to track the time since the last user interaction, turning the system off
 * @param timeStamp 
 */
function step(timeStamp:number) {

  if (start === undefined || start_flag) {
    start = timeStamp;
    start_flag = false;
  }
  const elapsed = timeStamp - start;
  if (previousTimeStamp !== timeStamp) {
    // Math.min() is used here to make sure the element stops at exactly 200px   
  }

  if (elapsed < timeout_threshold) {
    done = false;
    // Stop the animation after 2 seconds

  }else{
    if(!done){
      console.log("TIMEOUT");
      hit_timeout$.next('timeout');
    } 
    done = true;
  }
     window.requestAnimationFrame(step);

}

window.requestAnimationFrame(step);



@Injectable({
  providedIn: 'root'
})
export class RealtimedatabaseService {

  public num_inputs: number = 16;
  public user_values: Array<boolean> =  [];

  public user: any = null;
  private db: any = null;


  constructor() { 

    const app = initializeApp(firebaseConfig);

    const auth = getAuth(app);
    signInWithEmailAndPassword(auth, login.email, login.password)
    .then((userCredential) => {
      // Signed in 
      const user = userCredential.user;
      // ...
    })
    .catch((error) => {
      const errorCode = error.code;
      const errorMessage = error.message;
    });

    this.db = getDatabase();

    for(let i = 0; i < this.num_inputs; i++){
      this.user_values.push(false);
    }

    hit_timeout$.subscribe((event)=> {
      this.timeout();
    })

  }

  getCode(id: number) : string {
    switch(id){
      case 0: return 'f1_a'; 
      case 1: return 'f1_b'; 
      case 2: return 'f2_a'; 
      case 3: return 'f2_b'; 
      case 4: return 'f3_a'; 
      case 5: return 'f3_b'; 
      case 6: return 'f4_a'; 
      case 7: return 'f4_b'; 
      case 8: return 'f5_a'; 
      case 9: return 'f5_b'; 
      case 10: return 'f6_a'; 
      case 11: return 'f6_b'; 
      case 12: return 'f7_a'; 
      case 13: return 'f7_b'; 
      case 14: return 'f8_a'; 
      case 15: return 'f8_b'; 
    }
    return '';
  }
  


  /**
   * called if there has been no activity 
   */
  timeout(){
    for(let i = 0; i < 16; i++){
      this.deactivate(i);
    }
  }


  activate(id: number) {
    this.user_values[id] = true;
    let val = this.convertToInt();
    set(ref(this.db, 'bits'), val).then(success => {
      startCount();
    });
  }

  deactivate(id: number) {
    this.user_values[id] = false;
    let val = this.convertToInt();
    set(ref(this.db, 'bits'), val);
  }

  convertToInt() : number{
    let x = parseInt(this.user_values.map(i => (i) ? 1 : 0).join(''), 2);
    return x;
  }



}
