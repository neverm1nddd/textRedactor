#include "custombutton.h"

const qreal CUSTOM_BUTTON_SEARCH_DEFAULT_SIZE         = 23;
const qreal CUSTOM_BUTTON_SEARCH_ACTIVE_SIZE          = 27;

const qreal CUSTOM_BUTTON_ZOOM_DEFAULT_SIZE           = 17;
const qreal CUSTOM_BUTTON_ZOOM_ACTIVE_SIZE            = 19;

const qreal CUSTOM_BUTTON_CLOSE_DEFAULT_SIZE          = 20;
const qreal CUSTOM_BUTTON_CLOSE_ACTIVE_SIZE           = 22;

const qreal CUSTOM_BUTTON_SEARCH_APPLY_DEFAULT_SIZE   = 25;
const qreal CUSTOM_BUTTON_SEARCH_APPLY_ACTIVE_SIZE    = 27;

const qreal CUSTOM_BUTTON_FONT_DEFAULT_SIZE           = 20;
const qreal CUSTOM_BUTTON_FONT_ACTIVE_SIZE            = 22;

customButton::customButton(int bType_, QWidget *parent)
    : QPushButton{parent}
{
    bType = bType_;
    active = false;

    this->setStyleSheet("background-color: transparent; border: none;");

    switch(bType)
    {
        case eButtonType_search:
        {
            this->setIcon(QIcon(":/icons/magnifier.png"));
            this->setIconSize(QSize(CUSTOM_BUTTON_SEARCH_DEFAULT_SIZE, CUSTOM_BUTTON_SEARCH_DEFAULT_SIZE));
            this->setFixedSize(QSize(CUSTOM_BUTTON_SEARCH_DEFAULT_SIZE, CUSTOM_BUTTON_SEARCH_DEFAULT_SIZE));
            break;
        }
        case eButtonType_zoomIn:
        {
            this->setIcon(QIcon(":/icons/zoomIn.png"));
            this->setIconSize(QSize(CUSTOM_BUTTON_ZOOM_DEFAULT_SIZE, CUSTOM_BUTTON_ZOOM_DEFAULT_SIZE));
            this->setFixedSize(QSize(CUSTOM_BUTTON_ZOOM_DEFAULT_SIZE, CUSTOM_BUTTON_ZOOM_DEFAULT_SIZE));
            break;
        }
        case eButtonType_zoomOut:
        {
            this->setIcon(QIcon(":/icons/zoomOut.png"));
            this->setIconSize(QSize(CUSTOM_BUTTON_ZOOM_DEFAULT_SIZE, CUSTOM_BUTTON_ZOOM_DEFAULT_SIZE));
            this->setFixedSize(QSize(CUSTOM_BUTTON_ZOOM_DEFAULT_SIZE, CUSTOM_BUTTON_ZOOM_DEFAULT_SIZE));
            break;
        }
        case eButtonType_back:
        {
            this->setIcon(QIcon(":/icons/back.png"));
            this->setIconSize(QSize(CUSTOM_BUTTON_ZOOM_DEFAULT_SIZE, CUSTOM_BUTTON_ZOOM_DEFAULT_SIZE));
            this->setFixedSize(QSize(CUSTOM_BUTTON_ZOOM_DEFAULT_SIZE, CUSTOM_BUTTON_ZOOM_DEFAULT_SIZE));
            break;
        }
        case eButtobType_forward:
        {
            this->setIcon(QIcon(":/icons/forward.png"));
            this->setIconSize(QSize(CUSTOM_BUTTON_ZOOM_DEFAULT_SIZE, CUSTOM_BUTTON_ZOOM_DEFAULT_SIZE));
            this->setFixedSize(QSize(CUSTOM_BUTTON_ZOOM_DEFAULT_SIZE, CUSTOM_BUTTON_ZOOM_DEFAULT_SIZE));
            break;
        }
        case eButtonType_close:
        {
            this->setIcon(QIcon(":/icons/closeDefault.png"));
            this->setIconSize(QSize(CUSTOM_BUTTON_CLOSE_DEFAULT_SIZE, CUSTOM_BUTTON_CLOSE_DEFAULT_SIZE));
            this->setFixedSize(QSize(CUSTOM_BUTTON_CLOSE_DEFAULT_SIZE, CUSTOM_BUTTON_CLOSE_DEFAULT_SIZE));
            break;
        }
        case eButtonType_searchApply:
        {
            this->setIcon(QIcon(":/icons/searchApplyDefault.png"));
            this->setIconSize(QSize(CUSTOM_BUTTON_SEARCH_APPLY_DEFAULT_SIZE, CUSTOM_BUTTON_SEARCH_APPLY_DEFAULT_SIZE));
            this->setFixedSize(QSize(CUSTOM_BUTTON_SEARCH_APPLY_DEFAULT_SIZE, CUSTOM_BUTTON_SEARCH_APPLY_DEFAULT_SIZE));
            break;
        }
        case eButtonType_fontBold:
        case eButtonType_fontItalic:
        case eButtonType_fontUnderLine:
        case eButtonType_fontIncrease:
        case eButtonType_fontDecrease:
        {
            this->setIconSize(QSize(CUSTOM_BUTTON_FONT_DEFAULT_SIZE, CUSTOM_BUTTON_FONT_DEFAULT_SIZE));
            this->setFixedSize(QSize(CUSTOM_BUTTON_FONT_DEFAULT_SIZE, CUSTOM_BUTTON_FONT_DEFAULT_SIZE));
            switch(bType)
            {
                case eButtonType_fontBold:
                {
                    this->setIcon(QIcon(":/icons/fontBold.png"));
                    break;
                }
                case eButtonType_fontItalic:
                {
                    this->setIcon(QIcon(":/icons/fontItalic.png"));
                    break;
                }
                case eButtonType_fontUnderLine:
                {
                    this->setIcon(QIcon(":/icons/fontUnderline.png"));
                    break;
                }
                case eButtonType_fontIncrease:
                {
                    this->setIcon(QIcon(":/icons/fontIncrease.png"));
                    break;
                }
                case eButtonType_fontDecrease:
                {
                    this->setIcon(QIcon(":/icons/fontDecrease.png"));
                    break;
                }
            }
            break;
        }
        default:
            break;
    }
}

void customButton::setActive()
{
    if(!active)
    {
        this->setStyleSheet("background-color: rgba(80, 122, 175, 180); border-radius: 2px;");
        active = true;
        switch(bType)
        {
            case eButtonType_fontBold:
            {
                emit setFontBold(true);
                break;
            }
            case eButtonType_fontItalic:
            {
                emit setFontItalic(true);
                break;
            }
            case eButtonType_fontUnderLine:
            {
                emit setFontUnderline(true);
                break;
            }
            default:
                break;
        }
    }
    else
    {
        this->setStyleSheet("background-color: transparent; border: none;");
        active = false;
        switch(bType)
        {
            case eButtonType_fontBold:
            {
                emit setFontBold(false);
                break;
            }
            case eButtonType_fontItalic:
            {
                emit setFontItalic(false);
                break;
            }
            case eButtonType_fontUnderLine:
            {
                emit setFontUnderline(false);
                break;
            }
            default:
                break;
        }
    }
}

bool customButton::isActive()
{
    return active;
}

void customButton::enterEvent(QEnterEvent *event)
{
    Q_UNUSED(event)

    this->setCursor(Qt::PointingHandCursor);

    switch(bType)
    {
        case eButtonType_search:
        {
            this->setIconSize(QSize(CUSTOM_BUTTON_SEARCH_ACTIVE_SIZE, CUSTOM_BUTTON_SEARCH_ACTIVE_SIZE));
            this->setFixedSize(QSize(CUSTOM_BUTTON_SEARCH_ACTIVE_SIZE, CUSTOM_BUTTON_SEARCH_ACTIVE_SIZE));
            emit showHint("Поиск в тексте");
            break;
        }
        case eButtonType_zoomIn:
        {
            this->setIconSize(QSize(CUSTOM_BUTTON_ZOOM_ACTIVE_SIZE, CUSTOM_BUTTON_ZOOM_ACTIVE_SIZE));
            this->setFixedSize(QSize(CUSTOM_BUTTON_ZOOM_ACTIVE_SIZE, CUSTOM_BUTTON_ZOOM_ACTIVE_SIZE));
            emit showHint("Увеличить масштаб текста");
            break;
        }
        case eButtonType_zoomOut:
        {
            this->setIconSize(QSize(CUSTOM_BUTTON_ZOOM_ACTIVE_SIZE, CUSTOM_BUTTON_ZOOM_ACTIVE_SIZE));
            this->setFixedSize(QSize(CUSTOM_BUTTON_ZOOM_ACTIVE_SIZE, CUSTOM_BUTTON_ZOOM_ACTIVE_SIZE));
            emit showHint("Уменьшить масштаб текста");
            break;
        }
        case eButtonType_back:
        {
            this->setIconSize(QSize(CUSTOM_BUTTON_ZOOM_ACTIVE_SIZE, CUSTOM_BUTTON_ZOOM_ACTIVE_SIZE));
            this->setFixedSize(QSize(CUSTOM_BUTTON_ZOOM_ACTIVE_SIZE, CUSTOM_BUTTON_ZOOM_ACTIVE_SIZE));
            emit showHint("Вернуться назад");
            break;
        }
        case eButtobType_forward:
        {
            this->setIconSize(QSize(CUSTOM_BUTTON_ZOOM_ACTIVE_SIZE, CUSTOM_BUTTON_ZOOM_ACTIVE_SIZE));
            this->setFixedSize(QSize(CUSTOM_BUTTON_ZOOM_ACTIVE_SIZE, CUSTOM_BUTTON_ZOOM_ACTIVE_SIZE));
            emit showHint("Вернуться вперед");
            break;
        }
        case eButtonType_close:
        {
            this->setIcon(QIcon(":/icons/closeActive.png"));
            this->setIconSize(QSize(CUSTOM_BUTTON_CLOSE_ACTIVE_SIZE, CUSTOM_BUTTON_CLOSE_ACTIVE_SIZE));
            this->setFixedSize(QSize(CUSTOM_BUTTON_CLOSE_ACTIVE_SIZE, CUSTOM_BUTTON_CLOSE_ACTIVE_SIZE));
            emit showHint("Закрыть окно поиска");
            break;
        }
        case eButtonType_searchApply:
        {
            this->setIcon(QIcon(":/icons/searchApplyActive.png"));
            this->setIconSize(QSize(CUSTOM_BUTTON_SEARCH_APPLY_ACTIVE_SIZE, CUSTOM_BUTTON_SEARCH_APPLY_ACTIVE_SIZE));
            this->setFixedSize(QSize(CUSTOM_BUTTON_SEARCH_APPLY_ACTIVE_SIZE, CUSTOM_BUTTON_SEARCH_APPLY_ACTIVE_SIZE));
            emit showHint("Найти в тексте");
            break;
        }
        case eButtonType_fontBold:
        case eButtonType_fontItalic:
        case eButtonType_fontUnderLine:
        case eButtonType_fontIncrease:
        case eButtonType_fontDecrease:
        {
            this->setIconSize(QSize(CUSTOM_BUTTON_CLOSE_ACTIVE_SIZE, CUSTOM_BUTTON_CLOSE_ACTIVE_SIZE));
            this->setFixedSize(QSize(CUSTOM_BUTTON_CLOSE_ACTIVE_SIZE, CUSTOM_BUTTON_CLOSE_ACTIVE_SIZE));
            switch(bType)
            {
                case eButtonType_fontBold:
                {
                    emit showHint("Сделать жирным");
                    break;
                }
                case eButtonType_fontItalic:
                {
                    emit showHint("Сделать курсивом");
                    break;
                }
                case eButtonType_fontUnderLine:
                {
                    emit showHint("Сделать подчеркнутым");
                    break;
                }
                case eButtonType_fontIncrease:
                {
                    emit showHint("Увеличить размер шрифта");;
                    break;
                }
                case eButtonType_fontDecrease:
                {
                    emit showHint("Уменьшить размер шрифта");
                    break;
                }
            }
            break;
        }
        default:
            break;
    }
}

void customButton::leaveEvent(QEvent *event)
{
    Q_UNUSED(event)

    this->setCursor(Qt::ArrowCursor);
    emit showHint("");

    switch(bType)
    {
        case eButtonType_search:
        {
            this->setIconSize(QSize(CUSTOM_BUTTON_SEARCH_DEFAULT_SIZE, CUSTOM_BUTTON_SEARCH_DEFAULT_SIZE));
            this->setFixedSize(QSize(CUSTOM_BUTTON_SEARCH_DEFAULT_SIZE, CUSTOM_BUTTON_SEARCH_DEFAULT_SIZE));
            break;
        }
        case eButtonType_back:
        case eButtobType_forward:
        case eButtonType_zoomIn:
        case eButtonType_zoomOut:
        {
            this->setIconSize(QSize(CUSTOM_BUTTON_ZOOM_DEFAULT_SIZE, CUSTOM_BUTTON_ZOOM_DEFAULT_SIZE));
            this->setFixedSize(QSize(CUSTOM_BUTTON_ZOOM_DEFAULT_SIZE, CUSTOM_BUTTON_ZOOM_DEFAULT_SIZE));
            break;
        }
        case eButtonType_close:
        {
            this->setIcon(QIcon(":/icons/closeDefault.png"));
            this->setIconSize(QSize(CUSTOM_BUTTON_CLOSE_DEFAULT_SIZE, CUSTOM_BUTTON_CLOSE_DEFAULT_SIZE));
            this->setFixedSize(QSize(CUSTOM_BUTTON_CLOSE_DEFAULT_SIZE, CUSTOM_BUTTON_CLOSE_DEFAULT_SIZE));
            break;
        }
        case eButtonType_searchApply:
        {
            this->setIcon(QIcon(":/icons/searchApplyDefault.png"));
            this->setIconSize(QSize(CUSTOM_BUTTON_SEARCH_APPLY_DEFAULT_SIZE, CUSTOM_BUTTON_SEARCH_APPLY_DEFAULT_SIZE));
            this->setFixedSize(QSize(CUSTOM_BUTTON_SEARCH_APPLY_DEFAULT_SIZE, CUSTOM_BUTTON_SEARCH_APPLY_DEFAULT_SIZE));
            break;
        }
        case eButtonType_fontBold:
        case eButtonType_fontItalic:
        case eButtonType_fontUnderLine:
        case eButtonType_fontIncrease:
        case eButtonType_fontDecrease:
        {
            this->setIconSize(QSize(CUSTOM_BUTTON_FONT_DEFAULT_SIZE, CUSTOM_BUTTON_FONT_DEFAULT_SIZE));
            this->setFixedSize(QSize(CUSTOM_BUTTON_FONT_DEFAULT_SIZE, CUSTOM_BUTTON_FONT_DEFAULT_SIZE));
            break;
        }
        default:
            break;
    }
}

void customButton::mousePressEvent(QMouseEvent *event)
{
    switch(bType)
    {
        case eButtonType_fontBold:
        case eButtonType_fontItalic:
        case eButtonType_fontUnderLine:
        case eButtonType_fontIncrease:
        case eButtonType_fontDecrease:
        {
            if(event->buttons() == Qt::LeftButton)
                setActive();
            break;
        }
        default:
        {
            emit clicked();
            break;
        }
    }
}
