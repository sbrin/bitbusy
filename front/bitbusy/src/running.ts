import { writable } from "svelte/store";

export const text = writable("Hello");
export const color = writable("#e01b24");

export function hexToRGB565(hex: String) {
  const r = parseInt(hex.slice(1, 3), 16);
  const g = parseInt(hex.slice(3, 5), 16);
  const b = parseInt(hex.slice(5, 7), 16);
  return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
}
