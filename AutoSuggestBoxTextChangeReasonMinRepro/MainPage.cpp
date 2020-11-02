#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"
#include <chrono>

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace std::chrono_literals;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::AutoSuggestBoxTextChangeReasonMinRepro::implementation
{
    MainPage::MainPage() : mSuggestions{ single_threaded_observable_vector<IInspectable>() }, mSuggestionWithoutToStrings{single_threaded_observable_vector<IInspectable>()}
    {
        InitializeComponent();
    }
}

void winrt::AutoSuggestBoxTextChangeReasonMinRepro::implementation::MainPage::AutoSuggestBox_TextChanged(winrt::Microsoft::UI::Xaml::Controls::AutoSuggestBox const& sender, winrt::Microsoft::UI::Xaml::Controls::AutoSuggestBoxTextChangedEventArgs const& args)
{
    if (args.Reason() == Microsoft::UI::Xaml::Controls::AutoSuggestionBoxTextChangeReason::UserInput)
    {
        UpdateSuggestions(sender.Text());
        auto debugText = L"Updating " + sender.Text() + L"\n";
        OutputDebugString(debugText.c_str());
    }
}

void winrt::AutoSuggestBoxTextChangeReasonMinRepro::implementation::MainPage::AutoSuggestBox_SuggestionChosen(winrt::Microsoft::UI::Xaml::Controls::AutoSuggestBox const& sender, winrt::Microsoft::UI::Xaml::Controls::AutoSuggestBoxSuggestionChosenEventArgs const& args)
{
    // If we comment out L"Custom display text", TextChanged would not report reason as UserInput.
    sender.Text(args.SelectedItem().as<AutoSuggestBoxTextChangeReasonMinRepro::SuggestionViewModel>().ToString() + L" and text set through suggestion chosen");
}

void winrt::AutoSuggestBoxTextChangeReasonMinRepro::implementation::MainPage::AutoSuggestBox_QuerySubmitted(winrt::Microsoft::UI::Xaml::Controls::AutoSuggestBox const& sender, winrt::Microsoft::UI::Xaml::Controls::AutoSuggestBoxQuerySubmittedEventArgs const& args)
{
}

Windows::Foundation::IAsyncAction winrt::AutoSuggestBoxTextChangeReasonMinRepro::implementation::MainPage::UpdateSuggestions(hstring query)
{
    apartment_context uiThread;
    co_await resume_background();
    // Pretend we are fetching things from the network
    co_await 500ms;
    co_await uiThread;
    mSuggestions.Clear();
    mSuggestions.Append(make<implementation::SuggestionViewModel>(query + L" A"));
    mSuggestions.Append(make<implementation::SuggestionViewModel>(query + L" B"));
}

void winrt::AutoSuggestBoxTextChangeReasonMinRepro::implementation::MainPage::AutoSuggestBox_TextChanged_Without_ToString(winrt::Microsoft::UI::Xaml::Controls::AutoSuggestBox const& sender, winrt::Microsoft::UI::Xaml::Controls::AutoSuggestBoxTextChangedEventArgs const& args)
{
    if (args.Reason() == Microsoft::UI::Xaml::Controls::AutoSuggestionBoxTextChangeReason::UserInput)
    {
        UpdateSuggestionWithoutToStrings(sender.Text());
        auto debugText = L"Updating " + sender.Text() + L"\n";
        OutputDebugString(debugText.c_str());
    }
}

void winrt::AutoSuggestBoxTextChangeReasonMinRepro::implementation::MainPage::AutoSuggestBox_SuggestionChosen_Without_ToString(winrt::Microsoft::UI::Xaml::Controls::AutoSuggestBox const& sender, winrt::Microsoft::UI::Xaml::Controls::AutoSuggestBoxSuggestionChosenEventArgs const& args)
{
    sender.Text(args.SelectedItem().as<AutoSuggestBoxTextChangeReasonMinRepro::SuggestionViewModelWithoutToString>().DisplayName());
}

void winrt::AutoSuggestBoxTextChangeReasonMinRepro::implementation::MainPage::AutoSuggestBox_QuerySubmitted_Without_ToString(winrt::Microsoft::UI::Xaml::Controls::AutoSuggestBox const& sender, winrt::Microsoft::UI::Xaml::Controls::AutoSuggestBoxQuerySubmittedEventArgs const& args)
{
}

Windows::Foundation::IAsyncAction winrt::AutoSuggestBoxTextChangeReasonMinRepro::implementation::MainPage::UpdateSuggestionWithoutToStrings(hstring query)
{
    apartment_context uiThread;
    co_await resume_background();
    // Pretend we are fetching things from the network
    co_await 500ms;
    co_await uiThread;
    mSuggestions.Clear();
    mSuggestions.Append(make<implementation::SuggestionViewModelWithoutToString>(query + L" A"));
    mSuggestions.Append(make<implementation::SuggestionViewModelWithoutToString>(query + L" B"));
}