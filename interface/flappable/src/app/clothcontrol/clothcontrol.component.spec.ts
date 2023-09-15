import { ComponentFixture, TestBed } from '@angular/core/testing';

import { ClothcontrolComponent } from './clothcontrol.component';

describe('ClothcontrolComponent', () => {
  let component: ClothcontrolComponent;
  let fixture: ComponentFixture<ClothcontrolComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ ClothcontrolComponent ]
    })
    .compileComponents();

    fixture = TestBed.createComponent(ClothcontrolComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
