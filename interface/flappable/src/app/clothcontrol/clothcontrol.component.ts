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

  setEMOn(id: number) {
    this.rtdb.activate(id);
  }

  setEMOff(id: number) {
    this.rtdb.deactivate(id);
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


}
