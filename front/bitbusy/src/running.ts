import { writable } from "svelte/store";

export const text = writable("Hello");
export const color = writable("#e01b24");

export function hexToRGB565(hex: String) {
  const r = parseInt(hex.slice(1, 3), 16);
  const g = parseInt(hex.slice(3, 5), 16);
  const b = parseInt(hex.slice(5, 7), 16);
  return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
}

export function rgb565ToHex(rgb565: number): string {
  const r = (rgb565 >> 11) & 0x1F;
  const g = (rgb565 >> 5) & 0x3F;
  const b = rgb565 & 0x1F;

  const r8 = (r << 3) | (r >> 2);  
  const g8 = (g << 2) | (g >> 4);  
  const b8 = (b << 3) | (b >> 2);  

  return (
    '#' +
    r8.toString(16).padStart(2, '0') +
    g8.toString(16).padStart(2, '0') +
    b8.toString(16).padStart(2, '0')
  );
}
