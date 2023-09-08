import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { ClothcontrolComponent } from './clothcontrol/clothcontrol.component';
import { RealtimedatabaseService } from './realtimedatabase.service';
import { NoopAnimationsModule } from '@angular/platform-browser/animations';
import {MatButtonModule} from '@angular/material/button';

@NgModule({
  declarations: [
    AppComponent,
    ClothcontrolComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    NoopAnimationsModule,
    MatButtonModule
  ],
  providers: [RealtimedatabaseService],
  bootstrap: [AppComponent]
})
export class AppModule { }
