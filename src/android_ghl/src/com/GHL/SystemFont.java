package com.GHL;

import android.graphics.Bitmap;
import android.graphics.Paint;
import android.graphics.Rect;
import android.graphics.Canvas;
import android.graphics.Color;

import android.util.Log;

public class SystemFont  {
	float m_size = 12.0f;
	Bitmap m_bitmap = null;
	Bitmap m_bitmap_gray = null;
	Bitmap m_bitmap_color = null;
	Paint m_paint = null;
	Rect m_bounds = null;
	float m_advance = 0.0f;
	int m_add_size = 0;

	char[] codeUnits = new char[2];

	public SystemFont() {
		m_paint = new Paint(Paint.ANTI_ALIAS_FLAG);
		m_bounds = new Rect();
		m_paint.setColor(Color.rgb(255,255,255));
		m_paint.setStyle(Paint.Style.FILL);
	}

	public Bitmap getBitmap() {
		return m_bitmap;
	}

	public Rect getBounds() {
		return m_bounds;
	}

	public int getX() {
		return -m_bounds.left;
	}
	public int getY() {
		return -m_bounds.top;
	}
	public int getW() {
		return m_bounds.width();
	}
	public int getH() {
		return m_bounds.height();
	}
	public float getAdvance() {
		return m_advance;
	}

	public void setSize(float s,float xs) {
		m_size = s;
		m_paint.setTextSize(m_size);
		if (xs != 1.0f) {
			m_paint.setTextScaleX(xs);
		}
	}
	public void setOutline(float ow) {
		m_paint.setStyle(Paint.Style.STROKE);
		m_paint.setStrokeWidth(ow*2);
		m_add_size = (int)(ow+0.5f);
	}
	public int getAscent() {
		return m_paint.getFontMetricsInt().ascent;
	}
	public int getDescent() {
		return m_paint.getFontMetricsInt().descent;
	}
	public boolean renderGlyph(int ch, boolean gray) {
		m_bounds.setEmpty();

		int count = Character.toChars(ch, codeUnits, 0); 
		String text = new String(codeUnits, 0, count);
		m_paint.getTextBounds(text, 0, text.length(), m_bounds);
		m_bounds.left -= m_add_size;
		m_bounds.right += m_add_size;
		m_bounds.top -= m_add_size;
		m_bounds.bottom += m_add_size;
		if (m_bounds.width < 1)
			m_bounds.right += 1;
		if (m_bounds.height < 1)
			m_bounds.height += 1;
		m_advance = m_paint.measureText(text);

		Log.i("Font","bounds: " + m_bounds.left + "," + m_bounds.top + " " + m_bounds.width() + "x" + m_bounds.height());

		if (m_bounds.isEmpty()) {
			return false;
		}

		Bitmap bitmap = gray ? m_bitmap_gray : m_bitmap_color;


		if (bitmap == null ||
			(bitmap.getWidth() < m_bounds.width()) ||
			(bitmap.getHeight() < m_bounds.height())) {
			bitmap = Bitmap.createBitmap(m_bounds.width(),m_bounds.height(),gray ? Bitmap.Config.ALPHA_8 : Bitmap.Config.ARGB_8888);
			if (android.os.Build.VERSION.SDK_INT >= 19) {
				bitmap.setPremultiplied(true);
			}
		}

		bitmap.eraseColor(Color.TRANSPARENT);

		Canvas canvas = new Canvas(bitmap);
		canvas.drawText(text, -m_bounds.left, -m_bounds.top, m_paint);

		m_bitmap = bitmap;

		if (gray) {
			m_bitmap_gray = bitmap;
		} else {
			m_bitmap_color = bitmap;
		}

		return true;

		// Canvas canvas = new Canvas(bitmap);
		
		// paint.setTextSize((int) size);

		// if (m_bitmap == null) {
		// 	m_bitmap = Bitmap.createBitmap(16,16,Bitmap.ARGB_8888);
		// }
	}
}