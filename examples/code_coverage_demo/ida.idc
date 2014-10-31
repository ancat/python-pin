#include <idc.idc>

static main(void) {
  auto x = fopen("instruc", "r");
  auto y = readstr(x);
  auto count = 50;
  auto b = atol(y);
  while(b){
	  print(b);
	  SetColor(b,CIC_ITEM, 0xc7c7ff);
	  y = readstr(x);
	  b = atol(y);
  }
  SetColor(0x080483ee, CIC_ITEM,  0xc7c7ff );
}