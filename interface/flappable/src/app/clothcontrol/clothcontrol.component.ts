import { Component, HostListener, OnInit } from '@angular/core';
import { RealtimedatabaseService } from '../realtimedatabase.service';



@Component({
  selector: 'app-clothcontrol',
  templateUrl: './clothcontrol.component.html',
  styleUrls: ['./clothcontrol.component.css']
})
export class ClothcontrolComponent implements OnInit{
  

  
  constructor(public rtdb: RealtimedatabaseService) { 


  }
  
  ngOnInit(): void {

  }

  allOn() : void {
    for(let i = 0; i < 16; i++){
      this.setEMOn(i);
    }
  }

  allOff() : void {
    for(let i = 0; i < 16; i++){
      this.setEMOff(i);
    }
  }

  setEMOn(id: number) {
    this.rtdb.activate(id);
  }

  setEMOff(id: number) {
    this.rtdb.deactivate(id);
  }

  @HostListener('unload', ['event'])
  unload(event:any){
    this.allOff();
    event.returnValue = "\\o/";

  }

  @HostListener('mousedown', ['$event'])
  mouseDown(event: any) {
    let target: string = (event.target !== null) ? event.target.id : 'null';

    if(target !== 'null'){
      let flap_id:number = parseInt(target.substring(0,1));
      let zone = target.substring(1, 2);
      console.log("FLAP ZONE ", flap_id, zone)
      let id = (zone == 'a') ? (flap_id-1)*2 : (flap_id-1)*2+1;
      this.rtdb.activate(id);

    }
  }

  @HostListener('touchstart', ['$event'])
  touchStart(event: any) {
    let target: string = (event.target !== null) ? event.target.id : 'null';

    if(target !== 'null'){
      let flap_id:number = parseInt(target.substring(0,1));
      let zone = target.substring(1, 2);
      console.log("FLAP ZONE ", flap_id, zone)
      let id = (zone == 'a') ? (flap_id-1)*2 : (flap_id-1)*2+1;
      this.rtdb.activate(id);

    }
  }

  @HostListener('mouseup', ['$event'])
  mouseUp(event: any) {
    let target: string = (event.target !== null) ? event.target.id : 'null';

    if(target !== 'null'){
      let flap_id:number = parseInt(target.substring(0,1));
      let zone = target.substring(1, 2);
      console.log("FLAP ZONE ", flap_id, zone)
      let id = (zone == 'a') ? (flap_id-1)*2 : (flap_id-1)*2+1;
      this.rtdb.deactivate(id);

    }
  }

  @HostListener('touchend', ['$event'])
  touchEnd(event: any) {
    let target: string = (event.target !== null) ? event.target.id : 'null';

    if(target !== 'null'){
      let flap_id:number = parseInt(target.substring(0,1));
      let zone = target.substring(1, 2);
      console.log("FLAP ZONE ", flap_id, zone)
      let id = (zone == 'a') ? (flap_id-1)*2 : (flap_id-1)*2+1;
      this.rtdb.deactivate(id);

    }
  }



  @HostListener('window:keydown.a', ['$event'])
    onAClick() {
      this.setEMOn(0);
    }

  @HostListener('window:keyup.a', ['$event'])
  onAUnClick() {
    this.setEMOff(0);
  }

  @HostListener('window:keydown.s', ['$event'])
  onSClick() {
    this.setEMOn(1);
  }
  
  @HostListener('window:keyup.s', ['$event'])
  onSUnClick() {
    this.setEMOff(1);
  }

  @HostListener('window:keydown.d', ['$event'])
  onDClick() {
    this.setEMOn(2);
  }
  
  @HostListener('window:keyup.d', ['$event'])
  onDUnClick() {
    this.setEMOff(2);
  }

  @HostListener('window:keydown.f', ['$event'])
  onFClick() {
    this.setEMOn(3);
  }
  
  @HostListener('window:keyup.f', ['$event'])
  onFUnClick() {
    this.setEMOff(3);
  }

  @HostListener('window:keydown.g', ['$event'])
  onGClick() {
    this.setEMOn(4);
  }
  
  @HostListener('window:keyup.g', ['$event'])
  onGUnClick() {
    this.setEMOff(4);
  }

  @HostListener('window:keydown.h', ['$event'])
  onHClick() {
    this.setEMOn(5);
  }
  
  @HostListener('window:keyup.h', ['$event'])
  onHUnClick() {
    this.setEMOff(5);
  }

  @HostListener('window:keydown.j', ['$event'])
  onJClick() {
    this.setEMOn(6);
  }
  
  @HostListener('window:keyup.j', ['$event'])
  onJUnClick() {
    this.setEMOff(6);
  }

  @HostListener('window:keydown.k', ['$event'])
  onKClick() {
    this.setEMOn(7);
  }
  
  @HostListener('window:keyup.k', ['$event'])
  onKUnClick() {
    this.setEMOff(7);
  }

  @HostListener('window:keydown.z', ['$event'])
  onZClick() {
    this.setEMOn(8);
  }
  
  @HostListener('window:keyup.z', ['$event'])
  onZUnClick() {
    this.setEMOff(8);
  }

  @HostListener('window:keydown.x', ['$event'])
  onXClick() {
    this.setEMOn(9);
  }
  
  @HostListener('window:keyup.x', ['$event'])
  onXUnClick() {
    this.setEMOff(9);
  }

  @HostListener('window:keydown.c', ['$event'])
  onCClick() {
    this.setEMOn(10);
  }
  
  @HostListener('window:keyup.c', ['$event'])
  onCUnClick() {
    this.setEMOff(10);
  }

  @HostListener('window:keydown.v', ['$event'])
  onVClick() {
    this.setEMOn(11);
  }
  
  @HostListener('window:keyup.v', ['$event'])
  onVUnClick() {
    this.setEMOff(11);
  }

  @HostListener('window:keydown.b', ['$event'])
  onBClick() {
    this.setEMOn(12);
  }
  
  @HostListener('window:keyup.b', ['$event'])
  onBUnClick() {
    this.setEMOff(12);
  }

  @HostListener('window:keydown.n', ['$event'])
  onNClick() {
    this.setEMOn(13);
  }
  
  @HostListener('window:keyup.n', ['$event'])
  onNUnClick() {
    this.setEMOff(13);
  }

  @HostListener('window:keydown.q', ['$event'])
  onQClick() {
    this.setEMOn(14);
  }
  
  @HostListener('window:keyup.q', ['$event'])
  onQUnClick() {
    this.setEMOff(14);
  }

  @HostListener('window:keydown.w', ['$event'])
  onWClick() {
    this.setEMOn(15);
  }
  
  @HostListener('window:keyup.w', ['$event'])
  onWUnClick() {
    this.setEMOff(15);
  }




}
