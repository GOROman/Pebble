// 激おこぷんぷん丸 for Pebble
//           Twitter: @GOROman

#include "pebble_os.h"
#include "pebble_app.h"
#include "pebble_fonts.h"

// ユニークID
#define MY_UUID { 0xE2, 0x68, 0x34, 0x6E, 0x36, 0x28, 0x44, 0x2C, 0xB8, 0x73, 0xEF, 0xCA, 0xAA, 0x6E, 0x66, 0x69 }

// アプリ情報
PBL_APP_INFO(MY_UUID,
             "PunPunMaru", "@GOROman",
             0, 1, /* App version */
             DEFAULT_MENU_ICON,
             APP_INFO_STANDARD_APP);

// メインウィンドウ
Window window;

// テキストレイヤー
TextLayer text_layer;

// ビットマップコンテナ
RotBmpPairContainer bitmap_container;

// 初期化時のハンドラ
void handle_init( AppContextRef ctx ) {
  (void)ctx;

  // ウィンドウの初期化
  window_init( &window, "PunPunMaru" );

  // ウィンドウを積む
  window_stack_push( &window, true );

  // フレームの原点の設定
  GRect layer_frame_description = layer_get_frame( &window.layer );
  layer_frame_description.origin.x = 0;
  layer_frame_description.origin.y = 0;

  // テキストレイヤーの初期化
  text_layer_init( &text_layer, layer_frame_description );

  // テキストレイヤーにテキストを表示
  text_layer_set_text( &text_layer, "\n"
		                   "\n"
		                   "\n"
		                   "\n"
		                   "\n"
		                   "\n"
		                   "\n"
		                   "\n"
		                   "  PUN PUN MARU\n"
		                   "\n"
		      );
  // レイヤーを登録
  layer_add_child( &window.layer, &text_layer.layer );

  // リソースの初期化
  resource_init_current_app( &APP_RESOURCES );

  // 白部分と黒部分のビットマップを登録
  rotbmp_pair_init_container(
    RESOURCE_ID_IMAGE_PUNPUNMARU_WHITE, 
    RESOURCE_ID_IMAGE_PUNPUNMARU_BLACK, 
    &bitmap_container
  );

  // レイヤーに追加
  layer_add_child( &window.layer, &bitmap_container.layer.layer );
}


// 終了時に呼ばれるハンドラ
void handle_deinit( AppContextRef ctx ) {
  (void)ctx;

  // ビットマップを開放
  rotbmp_pair_deinit_container( &bitmap_container );
}


void pbl_main( void *params ) {
  PebbleAppHandlers handlers = {
    .init_handler   = &handle_init,  // 初期化時に呼ばれるハンドラ
    .deinit_handler = &handle_deinit // 終了時に呼ばれるハンドラ
  };

  app_event_loop(params, &handlers);
}
